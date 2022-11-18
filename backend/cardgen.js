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
  a = makeid(8).toString();
  b = i.toString().padStart(4, "0");
  c = credit();
  console.log(card.create(a, b, i, c));

  if (c == 1) {
    d = Math.floor(Math.random() * 10) * -1000;
  } else {
    d = 0;
  }
  e = Math.floor(Math.random() * 251) * 8;
  f = makeid(5).toString();
  g = makeid(5).toString();
  console.log(account.create(f, a, e, 0));
  if (c == 1) {
    console.log(account.create(g, a, 0, d));
  }
}
