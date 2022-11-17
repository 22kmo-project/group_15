const card = require("./models/card_model");
const account = require("./models/account_model");

function makeid(length) {
  var result = "";
  var characters = "0123456789";
  var charactersLength = characters.length;
  for (var i = 0; i < length; i++) {
    result += characters.charAt(Math.floor(Math.random() * charactersLength));
  }
  return result;
}

console.log(makeid(8));

function credit() {
  var y = Math.random();
  if (y < 0.5) y = 0;
  else y = 1;
  return y;
}

for (var i = 1; i < 15; i++) {
  a = makeid(8);
  b = i.toString().padStart(4, "0");
  c = credit();
  console.log(card.add(a, b, i, c));

  if (c == 1) {
    d = Math.floor(Math.random() * 10) * 1000;
  } else {
    d = 0;
  }
  e = Math.floor(Math.random() * 251) * 8;
  f = makeid(5);
  console.log(account.add(f, a, e, d));
}
