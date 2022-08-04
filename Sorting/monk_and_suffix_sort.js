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
    const inputs = input.split(' ');
    const string = inputs[0];
    const k = parseInt(inputs[1]);

    const suffixes = [];

    for (let idx = 0; idx < string.length; idx ++) {
        suffixes.push(string.slice(idx));
    }

    suffixes.sort();
    console.log(suffixes[k - 1]);
}
