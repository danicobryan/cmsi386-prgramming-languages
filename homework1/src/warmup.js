// Homework 1

function change(amount) {
  if (amount < 0) {
    throw new RangeError('amount cannot be negative');
  }
  const result = [];
  let remaining = amount;
  [25, 10, 5, 1].forEach((coin) => {
    result.push(Math.floor(remaining / coin));
    remaining %= coin;
  });
  return result;
} // Creds to Dr. Toal's in-class example

function stripQuotes(string) {
  if (string === '') {
    return string;
  }
  let result = string;
  result = result.replace(/\\|['"]+/g, ''); // Creds to Jackson for help with regular expressions
  return result;
}

function scramble(string) {
  if (string === '') {
    return string;
  }
  const indivChars = string.split('');
  // Creds to Jackson/Alejandro for the idea to use the Fisher-Yates Shuffle Algorithm.
  for (let charToSwap = indivChars.length - 1; charToSwap >= 1; charToSwap -= 1) {
    const randomIndex = Math.floor(Math.random() * (charToSwap + 1));
    const temp = indivChars[randomIndex];
    indivChars[randomIndex] = indivChars[charToSwap];
    indivChars[charToSwap] = temp;
  }
  const result = indivChars.join('');
  return result;
}


function powers(base, limit, callback) {
  let answer = 0;
  let exponent = 0;
  if (limit > 0) {
    while (answer < limit) {
      answer = base ** exponent;
      if (answer <= limit) {
        callback(answer);
        exponent += 1;
      } else {
        break;
      }
    }
  }
}

function* powersGenerator(base, limit) {
  let answer = 0;
  let exponent = 0;
  if (limit > 0) {
    while (true) {
      answer = base ** exponent;
      if (answer <= limit) {
        yield answer;
        exponent += 1;
      } else {
        break;
      }
    }
  }
}

function say(string1) {
  let result = string1;
  if (result == null) {
    return '';
  }
  return function a(string2) {
    if (string2 == null) {
      return result;
    }
    result += ` ${string2}`;
    return say(result);
  };
}

function interleave(arr, ...a) {
  const array1 = arr;
  const array2 = [...a];
  let longerArray = array1;
  let shorterArray = array2;
  if (array2.length > array1.length) {
    longerArray = array2;
    shorterArray = array1;
  }
  const result = [];
  for (let index = 0; index < shorterArray.length; index += 1) {
    result.push(array1[index]);
    if (array2[index] != null) {
      result.push(array2[index]);
    }
  }
  for (let index = shorterArray.length; index < longerArray.length; index += 1) {
    result.push(longerArray[index]);
  }
  return result;
}

const crypto = require('crypto');

function makeCryptoFunctions(key, algorithm) {
  return [
    function encrypt(str) {
      const encryption = crypto.createCipher(algorithm, key);
      let crypted = encryption.update(str, 'utf8', 'hex');
      crypted += encryption.final('hex');
      return crypted;
    },
    function decrypt(str) {
      const decryption = crypto.createDecipher(algorithm, key);
      let decrypted = decryption.update(str, 'hex', 'utf8');
      decrypted += decryption.final('utf8');
      return decrypted;
    },
  ];
} // Creds to csanz on GitHub for an implementation of Node's crypto module

function cylinder(spec) {
  let { radius = 1, height = 1 } = spec;

  const surfaceArea = () => (2 * (Math.PI * (radius ** 2))) + (2 * Math.PI * radius * height);
  const volume = () => Math.PI * (radius ** 2) * height;
  const widen = (factor) => { radius *= factor; };
  const stretch = (factor) => { height *= factor; };
  const toString = () => `Cylinder with radius ${radius} and height ${height}`;
  return Object.freeze({
    get radius() {
      return radius;
    },
    get height() {
      return height; // Creds to Tyler for help with getter functions
    },
    surfaceArea,
    volume,
    widen,
    stretch,
    toString,
  });
}

const rp = require('request-promise');

function randomName(spec) {
  const { gender, region } = spec;

  const options = {
    uri: 'http://uinames.com/api/',
    qs: {
      amount: 1,
      gender,
      region,
    },
    json: true,
  };

  return rp(options)
    .then(result => `${result.surname}, ${result.name}`);
} // Creds to Haley for helping me with randomName.

module.exports = {
  change,
  stripQuotes,
  scramble,
  powers,
  powersGenerator,
  say,
  makeCryptoFunctions,
  cylinder,
  interleave,
  randomName,
};
