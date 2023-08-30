// TODO: Add code to check answers to questions
var btn1 = document.getElementById('btn1');
var btn2 = document.getElementById('btn2');
var btn3 = document.getElementById('btn3');
var btn4 = document.getElementById('btn4');
var btn5 = document.getElementById('btn5');
var feedback = document.getElementById('feedback');

btn1.addEventListener('click', checkAnswer);
btn2.addEventListener('click', checkAnswer);
btn3.addEventListener('click', checkAnswer);
btn4.addEventListener('click', checkAnswer);
btn5.addEventListener('click', checkAnswer);

function checkAnswer(event) {
var clickedBtn = event.target;

if (clickedBtn.id === 'btn5') {

    clickedBtn.style.backgroundColor = 'green';
} else {

    clickedBtn.style.backgroundColor = 'red';
}
}

document.getElementById("confirmBtn").addEventListener("click", function() {
var answer = document.getElementById("answer").value;
var feedback = document.getElementById("feedback");

if (answer === "switzerland") {
    document.getElementById("answer").style.backgroundColor = "green";
    feedback.style.color = "green";
} else {
    document.getElementById("answer").style.backgroundColor = "red";
    feedback.style.color = "red";
}
});
