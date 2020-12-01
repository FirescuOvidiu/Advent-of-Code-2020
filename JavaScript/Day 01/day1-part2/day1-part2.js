const fs = require("fs");
const input = fs
  .readFileSync("input.in", { encoding: "utf8", flag: "r" })
  .split("\n")
  .map(Number);

for (let i = 0; i < input.length - 2; i++) {
  for (let j = i + 1; j < input.length - 1; j++) {
    for (let k = j + 1; k < input.length; k++) {
      if (input[i] + input[j] + input[k] == 2020) {
        fs.writeFileSync(
          "output.out",
          (input[i] * input[j] * input[k]).toString()
        );
      }
    }
  }
}
