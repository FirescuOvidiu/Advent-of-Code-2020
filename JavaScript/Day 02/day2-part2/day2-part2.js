const fs = require("fs");
const data = fs
  .readFileSync("input.in", { encoding: "utf8", flag: "r" })
  .toString()
  .split("\n")
  .map((el) => el.split(" "))
  .map((el) => {
    let [lowest, highest] = el[0].split("-");
    return [parseInt(lowest), parseInt(highest), el[1].split(":")[0], el[2]];
  });
let countPasswords = 0;

for (el of data) {
  const [lowest, highest, letter, password] = el;

  if (
    (password[lowest - 1] === letter || password[highest - 1] === letter) &&
    password[lowest - 1] != password[highest - 1]
  ) {
    countPasswords++;
  }
}

fs.writeFileSync("output.out", countPasswords.toString());
