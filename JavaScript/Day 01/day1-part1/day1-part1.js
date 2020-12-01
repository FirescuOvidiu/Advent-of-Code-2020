const fs = require("fs");
const input = fs
  .readFileSync("input.in", { encoding: "utf8", flag: "r" })
  .split("\n")
  .map(Number);

for (let i = 0; i < input.length - 1; i++) {
  for (let j = i + 1; j < input.length; j++) {
    if (input[i] + input[j] == 2020) {
      fs.writeFileSync("output.out", (input[i] * input[j]).toString());
      i = j = input.length;
    }
  }
}
