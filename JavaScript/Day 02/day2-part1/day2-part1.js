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
  let countLetters = 0;

  for (pass of password) {
    if (pass === letter) {
      countLetters++;
    }
  }
  if (countLetters >= lowest && countLetters <= highest) {
    countPasswords++;
  }
}

fs.writeFileSync("output.out", countPasswords.toString());
