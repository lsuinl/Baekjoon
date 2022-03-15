const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let suin;

rl.on("line", (line) => {
  rl.close();
  suin=line;
});

console.log(suin);
rl.on("close",()=>{
  process.exit();
})

// html css javascript 로 아무거나 만들기 전부다 포함해서