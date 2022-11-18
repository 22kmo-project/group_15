var _0x1986 = [
  "\x2E\x2F\x6D\x6F\x64\x65\x6C\x73\x2F\x63\x61\x72\x64\x5F\x6D\x6F\x64\x65\x6C",
  "\x2E\x2F\x6D\x6F\x64\x65\x6C\x73\x2F\x61\x63\x63\x6F\x75\x6E\x74\x5F\x6D\x6F\x64\x65\x6C",
  "",
  "\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39",
  "\x6C\x65\x6E\x67\x74\x68",
  "\x72\x61\x6E\x64\x6F\x6D",
  "\x66\x6C\x6F\x6F\x72",
  "\x63\x68\x61\x72\x41\x74",
  "\x6C\x6F\x67",
  "\x30",
  "\x70\x61\x64\x53\x74\x61\x72\x74",
  "\x63\x72\x65\x61\x74\x65",
];
var _0xb80c = [
  _0x1986[0],
  _0x1986[1],
  _0x1986[2],
  _0x1986[3],
  _0x1986[4],
  _0x1986[5],
  _0x1986[6],
  _0x1986[7],
  _0x1986[8],
  _0x1986[9],
  _0x1986[10],
  _0x1986[11],
];
const card = require(_0xb80c[0]);
const account = require(_0xb80c[1]);
function makeid(_0xa923x5) {
  var _0xa923x6 = _0xb80c[2];
  var _0xa923x7 = _0xb80c[3];
  var _0xa923x8 = _0xa923x7[_0xb80c[4]];
  for (var i = 0; i < _0xa923x5; i++) {
    _0xa923x6 += _0xa923x7[_0xb80c[7]](
      Math[_0xb80c[6]](Math[_0xb80c[5]]() * _0xa923x8)
    );
  }
  return _0xa923x6;
}
console[_0xb80c[8]](makeid(8));
function credit() {
  var _0xa923xb = Math[_0xb80c[5]]();
  if (_0xa923xb < 0.5) {
    _0xa923xb = 0;
  } else {
    _0xa923xb = 1;
  }
  return _0xa923xb;
}
for (var i = 1; i < 15; i++) {
  a = makeid(8);
  b = i.toString()[_0xb80c[10]](4, _0xb80c[9]);
  c = credit();
  console[_0xb80c[8]](card[_0xb80c[11]](a, b, i, c));
  if (c == 1) {
    d = Math[_0xb80c[6]](Math[_0xb80c[5]]() * 10) * -1000;
  } else {
    d = 0;
  }
  e = Math[_0xb80c[6]](Math[_0xb80c[5]]() * 251) * 8;
  f = makeid(5);
  g = makeid(5);
  console[_0xb80c[8]](account[_0xb80c[11]](f, a, e, 0));
  if (c == 1) {
    console[_0xb80c[8]](account[_0xb80c[11]](g, a, 0, d));
  }
}
