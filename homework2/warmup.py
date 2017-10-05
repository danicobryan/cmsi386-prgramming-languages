import random
import math
import json
import requests

def change(amount):
    if amount < 0:
        raise ValueError('amount cannot be negative')
    result = []
    remaining = amount
    coins = [25, 10, 5, 1]
    for c in coins:
        result.append(remaining // c)
        remaining %= c
    return tuple(result)

def strip_quotes(s):
    return s.translate(str.maketrans("", "", '\'' + '\"'))

def scramble(s):
    characters = list(s)
    j = len(characters) - 1
    while j > 0:
        i = random.randint(0, j)
        characters[i], characters[j] = characters[j], characters[i]
        j -= 1
    return ''.join(characters)

def say(first_string=''):
    if first_string == '':
        return first_string
    def say2(next_string=''):
        if next_string == '':
            return first_string
        return say(first_string + " " + next_string)
    return say2

def triples(limit):
    result = []
    for c in range(1, limit + 1):
        for b in range(1, c):
            for a in range(1, b):
                if c * c == a * a + b * b:
                    l = (a, b, c)
                    result.append(l)
    return sorted(result, key=lambda x: x[0])

def powers(base, limit):
    power = 1
    while power <= limit:
        yield power
        power *= base

def interleave(a, *b):
    first_length = len(a)
    second_length = len(b)
    maximum = max(first_length, second_length)
    result = []
    for i in range(0, maximum):
        if i < first_length:
            result.append(a[i])
        if i < second_length:
            result.append(b[i])
    return result

class Cylinder:
    def __init__(self, radius=1, height=1):
        self.radius = radius
        self.height = height

    @property
    def surface_area(self):
        return (2 * (math.pi * (self.radius ** 2))) + (2 * math.pi * self.radius * self.height)
    @property
    def volume(self):
        return math.pi * (self.radius * self.radius) * self.height

    def widen(self, factor):
        self.radius *= factor

    def stretch(self, factor):
        self.height *= factor

def make_crypto_functions():
    return

def random_name(gender, region):
    url = 'http://uinames.com/api/'
    kwargs = {
        'amount': 1,
        'gender': gender,
        'region': region
    }
    info = requests.get(url=url, params=kwargs)
    person = json.loads(info.content)
    if 'error' in person:
        raise ValueError('{"error":"Invalid gender"}')
    result = person.get('surname') + ', '   + person.get('name')
    return result
