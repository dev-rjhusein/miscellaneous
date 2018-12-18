
const colorDisplay = document.getElementById("goalColor");
const messageDisplay = document.querySelector("#gameMsg");
const levels = document.querySelectorAll(".levels");
const newGame = document.querySelector("#newGame");
const hintImg = document.querySelector("#hint-image");
const easyBtn = document.querySelector("#easy");
const hardBtn = document.querySelector("#hard");
const impBtn = document.querySelector("#impossible");

let newColors = [];
let winningColor = 0;
let selectedLevel = "Easy";
let numberOfClicks = 0;

for(let i = 0; i < 50; i++){
    let newSq = document.createElement('div');
    newSq.setAttribute("class", "colorSquare");
    document.querySelector("#squareGrid").appendChild(newSq);
}
const squares = document.querySelectorAll(".colorSquare");

SetColorValues();

document.addEventListener("keyup", function(key){
    if(key.keyCode == 72){
        hintImg.style.display = "flex";
        setTimeout(function(){
            hintImg.style.display = "none";
            
        }, 5000);
    }
})


//New Game listener
newGame.addEventListener("click", function(){
    SetColorValues();
    numberOfClicks = 0;
    newGame.textContent = "New Colors";
});

//Difficulty listeners
for(let i = 0; i < levels.length; i+=1){
    levels[i].addEventListener("click", function(){
        selectedLevel = this.innerHTML;
        SetColorValues();
    })
}

//Game board listeners
for (let i = 0; i < squares.length; i +=1){

    //add initial colors to squares
    squares[i].style.backgroundColor = newColors[i];

    //click listeners to squares
    squares[i].addEventListener("click", function(){
        let clickedColor = this.style.backgroundColor
        
        //If winner
        if (clickedColor === winningColor){
            numberOfClicks += 1;
            let stries = "";
            if(numberOfClicks === 1){
                stries = " try.";
            }
            else{
                stries = " tries.";
            }
            newGame.textContent = "Play Again?";
            document.querySelector("#optionBar").style.backgroundColor = "green";
            messageDisplay.textContent = "Good Job! " + numberOfClicks + stries;
            WinningColors(winningColor);
            
        }
        //if loser
        else{
            numberOfClicks += 1;
            document.querySelector("#optionBar").style.backgroundColor = "red";
            setTimeout(function(){
                document.querySelector("#optionBar").style.backgroundColor = "white";},100);
            messageDisplay.textContent = "Try Again!";
            this.style.backgroundColor = "rgb(23, 23, 23)";
        }
    })
}








////////////////////// Functions ////////////////////////``
function WinningColors(color){
    for(let i = 0; i < squares.length; i+=1){
        squares[i].style.backgroundColor = color;
    }
}

function PickAColor(){
    let first = Math.floor(Math.random() * 255);
    let second = Math.floor(Math.random() * 255);
    let third = Math.floor(Math.random() * 255);

    return "rgb(" + first + ", " + second + ", " + third + ")";
}

function SetColorValues(){
    let repeat = 0;
    switch(selectedLevel){
        case "Easy":
            easyBtn.classList.add("selected"); 
            hardBtn.classList.remove("selected");
            impBtn.classList.remove("selected");
            repeat = 5;
            break;
        case "Hard":
            easyBtn.classList.remove("selected"); 
            hardBtn.classList.add("selected");
            impBtn.classList.remove("selected");
            repeat = 10;
            break;
        case "Impossible":
            easyBtn.classList.remove("selected"); 
            hardBtn.classList.remove("selected");
            impBtn.classList.add("selected");
            repeat = squares.length;
            break;
        default:
            repeat = 5;
    }
    newColors = [];
    for ( let i = 0; i < repeat; i+=1){
        newColors.push(PickAColor());
    }
    SetHTMLColors();

    //Display Goal Color
    winningColor = newColors[Math.floor(Math.random() * repeat)];
    colorDisplay.innerHTML = winningColor;
}

function SetHTMLColors(){
    for(let i = 0; i < newColors.length; i+=1){
        squares[i].style.display = "block";
        squares[i].style.backgroundColor = newColors[i];
    }
    for(let i = newColors.length; i < squares.length; i+=1){
        squares[i].style.display = "none";
    }
}