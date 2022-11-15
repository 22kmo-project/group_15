var express = require("express");
var path = require("path");
var cookieParser = require("cookie-parser");
var logger = require("morgan");

var indexRouter = require("./routes/index");
var loginRouter = require("./routes/login");

var app = express();

app.use(logger("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, "public")));

//suojaamaton
app.use("/login", loginRouter);

//suojattu
app.use(authenticate);
app.use("/", indexRouter);

function authenticate(req, res, next) {
  const authHeader = req.headers["authorization"];
  const token = authHeader && authHeader.split(" ")[1];

  console.log("token = " + token);
  if (token == null) return res.sendStatus(401);

  jwt.verify(token, process.env.MY_TOKEN, (err, card) => {
    console.log(err);

    if (err) return res.sendStatus(403);

    req.card = card;

    next();
  });
}

module.exports = app;
