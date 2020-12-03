const fs = require("fs");
const data = fs
  .readFileSync("input.in", { encoding: "utf8", flag: "r" })
  .toString()
  .split("\r\n")
  .map(String);

let x = 0,
  y = 0,
  countTrees = 0;
const rows = data.length,
  columns = data[0].length;
while (x < rows) {
  if (data[x][y] == "#") {
    countTrees++;
  }
  x++;
  y = (y + 3) % columns;
}

fs.writeFileSync("output.out", countTrees.toString());
