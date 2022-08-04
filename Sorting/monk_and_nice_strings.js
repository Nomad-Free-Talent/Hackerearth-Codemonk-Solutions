process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";

process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});

process.stdin.on("end", function () {
   main(stdin_input);
});

function main(input) {
    const lines = input.split('\n');
    const strings = lines.slice(1);

    strings.forEach((string, index) => {
        let cnt = 0;
        for (let idx = 0; idx < index; idx ++) {
            if (strings[idx].localeCompare(string) < 0) {
                cnt ++;
            }
        }
        console.log(cnt);
    })
}
