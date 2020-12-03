const fs = require("fs");
const data = fs
  .readFileSync("input.in", { encoding: "utf8", flag: "r" })
  .toString()
  .split("\r\n")
  .map(String);

const countTrees = (right, down) => {
  let x = 0,
    y = 0,
    countTrees = 0;
  const rows = data.length,
    columns = data[0].length;

  while (x < rows) {
    if (data[x][y] == "#") {
      countTrees++;
    }
    x = x + down;
    y = (y + right) % columns;
  }

  return countTrees;
};

let multiply = countTrees(1, 1);
multiply *= countTrees(3, 1);
multiply *= countTrees(5, 1);
multiply *= countTrees(7, 1);
multiply *= countTrees(1, 2);

fs.writeFileSync("output.out", multiply.toString());
