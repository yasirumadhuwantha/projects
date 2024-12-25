
const inputDisplay = document.getElementById("input");

function button(input) {
    inputDisplay.value += input;
}

function inputClear() {
    inputDisplay.value = "";
}

function calculate() {
    inputDisplay.value = eval(inputDisplay.value);
}
