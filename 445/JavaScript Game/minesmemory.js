var clickX;
var clickY;
var hasClicked = 0;
var clickEnabled = true;
var click1 = "";
var click2 = "";
var matched = 0;
var strikes = 0;
const canvas = document.getElementById("gameBoard")
const ctx = canvas.getContext("2d")
var images = [];
var cardsClicked = [];
var cardsFound = [];
//image variables and array of images and array of image locations
const boulder = new Image(100,100);
const rover = new Image(100,100);
const co209 = new Image(100,100);
const csu = new Image(100,100);
const elm = new Image(100,100);
const football = new Image(100,100);
const bigM = new Image(100,100);
const mesa = new Image(100,100);
const metro = new Image(100,100);
const mines = new Image(100,100);
const rec_center = new Image(100,100);
const stratton = new Image(100,100);
const thomas = new Image(100,100);
const mcoverup = new Image(100,100);
const marvin = new Image(100,100);
const blaster = new Image(100,100);
mcoverup.src = "./images/mcoverup.jpg";
mcoverup.id = "mcoverup";
boulder.src = "./images/boulder.jpg";
boulder.id = "boulder";
rover.src = "./images/rover.jpg";
rover.id = "rover";
co209.src = "./images/CO209.jpg";
co209.id = "CO209";
csu.src = "./images/csu_logo.jpg";
csu.id = "csu";
elm.src = "./images/elm.jpg";
elm.id = "elm";
football.src = "./images/football_field.jpg";
football.id = "football field";
bigM.src = "./images/M.jpg";
bigM.id = "M";
mesa.src = "./images/mesa.jpg";
mesa.id = "mesa";
metro.src = "./images/metro.jpg";
metro.id = "metro";
mines.src = "./images/mines_logo.jpg";
mines.id = "mines";
rec_center.src = "./images/rec_center.jpg";
rec_center.id = "Rec Center";
stratton.src = "./images/stratton.jpg";
stratton.id = "stratton";
thomas.src = "./images/thomas.jpg";
thomas.id = "thomas";
marvin.src = "./images/marvin.jpeg";
marvin.id = "marvin";
blaster.src = "./images/blaster.jpg";
blaster.id = "blaster";
//array of cards and of card locations on canvas
var array = [boulder,rover,thomas,stratton,mines,bigM,elm,co209,csu,blaster,rec_center,football,marvin,metro,mines,boulder,rover,thomas,stratton,bigM,elm,co209,csu,blaster,rec_center,football,metro,marvin];
var imageLocations =[25,0,25,100,25,200,25,300,168,0,168,100,168,200,168,300,311,0,311,100,311,200,311,300,454,0,454,100,454,200,454,300,597,0,597,100,597,200,597,300,740,0,740,100,740,200,740,300,883,0,883,100,883,200,883,300];
//randomize array
shuffle(array);
shuffle(array);
var scaleX = 100;
var scaleDirection = -1;
var scaleDelta =10; // determines speed
var PI2 = Math.PI*2;
var cardX;
var cardY;
var flipCard;


function cardLocation(name,x,y,image){
    this.name = name;
    this.x = x;
    this.y = y;
    this.image = image;
}

//on window load draw the images
window.addEventListener('load',function(){
    var count = 0;
    for(let i = 0; i < array.length; i++){
        ctx.drawImage(mcoverup,imageLocations[count],imageLocations[count+1],100,100);
        images.push(new cardLocation(array[i].id,imageLocations[count],imageLocations[count+1],array[i]));
        count += 2;
    }
});

function checkClicks(){
    if(cardsClicked.length == 2){ //check if user has clicked two cards
        clickEnabled = false; //diable clicked while comparing cards
        hasClicked = 0; //reset click counter to zero
        if(cardsClicked[0].name == cardsClicked[1].name && (cardsClicked[0].x != cardsClicked[1].x || cardsClicked[0].y != cardsClicked[1].y)){ //if both cards match
            // checks if they matched bad cards
            if(cardsClicked[0].name == "mesa" || cardsClicked[0].name == "csu" || cardsClicked[0].name == "metro" || cardsClicked[0].name == "boulder") {
              alert("You matched two bad cards and have lost the game! Press OK to restart.");
              document.location.reload(true);
            }
            matched += 1;
            document.getElementById("pairsCount").innerText = matched;
            if(matched == 11) {
              alert("Great job, you have won the game! Press OK to restart.");
            }
            document.getElementById("strikeCount").innerText = strikes;
            // add cards to array of cards that have been matched
            cardsFound.push(cardsClicked[0]);
            cardsFound.push(cardsClicked[1]);
            cardsClicked = [];
            clickEnabled = true; // reenable clicking on cards
        } else {
          if(cardsClicked[0].name == "csu" || cardsClicked[0].name == "mesa" || cardsClicked[0].name == "metro" || cardsClicked[0].name == "boulder" || cardsClicked[1].name == "csu" || cardsClicked[1].name == "mesa" || cardsClicked[1].name == "metro" || cardsClicked[1].name == "boulder"){
            strikes = strikes + 1; //increments the amount of strikes
          }
            document.getElementById("strikeCount").innerText = strikes;
            if(strikes == 7) {
                setTimeout(function(){
                    alert("You have flipped over 7 rival cards in 7 different turns, and have lost the game! Press OK to restart.");
                    document.location.reload(true);
                },100);   
            }
            setTimeout(function(){ //after 2000 ms change the images back to background and reenable clicking
                flipCard = cardsClicked[0].image;
                cardX = cardsClicked[0].x;
                cardY = cardsClicked[0].y
                scaleX = 100;
                animate2();
                //ctx.drawImage(mcoverup,cardsClicked[0].x,cardsClicked[0].y,100,100);
                setTimeout(function(){
                    flipCard = cardsClicked[1].image;
                    cardX = cardsClicked[1].x;
                    cardY = cardsClicked[1].y
                    scaleX = 100;
                    animate2();
                    cardsClicked = [];
                },750);
                //ctx.drawImage(mcoverup,cardsClicked[1].x,cardsClicked[1].y,100,100);
            },1000);


        }
    }
}
//checks what card is clicked based on x and y values of user mouse click
function findClickedCard(xClick,yClick){
    for(let i = 0; i < images.length; i++){
        if(xClick >= images[i].x && xClick <= (images[i].x+100) && yClick >= images[i].y && yClick <= (images[i].y+100)){
            if(!cardsFound.includes(images[i]) && !cardsClicked.includes(images[i])){ // check card has been clicked already or matched already
                if(hasClicked == 1){ // if this is first card clicked
                    flipCard = images[i].image;
                    cardX = images[i].x;
                    cardY = images[i].y;
                    scaleX = 100;
                    animate();
                    //ctx.drawImage(images[i].image,images[i].x,images[i].y,100,100);
                    cardsClicked.push(images[i]);
                    if(cardsClicked[0].name == "csu" || cardsClicked[0].name == "mesa" || cardsClicked[0].name == "metro" || cardsClicked[0].name == "boulder"){
                        if(strikes ==6) {
                            strikes = strikes + 1; //increments the amount of strikes
                            document.getElementById("strikeCount").innerText = strikes;
                            setTimeout(function(){
                                alert("You have flipped over 3 rival cards in 3 different turns, and have lost the game! Press OK to restart.");
                                document.location.reload(true);
                            },350);   
                        }
                      }
                }
                else{ // 2 cards have been clicked so checkClicks();
                    flipCard = images[i].image;
                    cardX = images[i].x;
                    cardY = images[i].y;
                    scaleX = 100;
                    animate();
                    //ctx.drawImage(images[i].image,images[i].x,images[i].y,100,100);
                    cardsClicked.push(images[i]);
                    setTimeout(function(){
                        checkClicks();
                    },750);
                }
            } else {
                hasClicked -= 1; // card has been matched or clicked already so dont include it
            }
        }
    }
}

function getMousePosition(canvas, event) {
    let rect = canvas.getBoundingClientRect();
    let x = event.clientX - rect.left; //subtract event x's position from bounding rectangle's x position
    let y = event.clientY - rect.top; //subtract event y's position from bounding rectangle's y position
    hasClicked += 1;
    findClickedCard(x,y);
    //console.log("Coordinate x: " + x + " Coordinate y: " + y);
}

let canvasElem = document.querySelector("canvas");

canvasElem.addEventListener("mousedown", function(e){
    if(clickEnabled){ // check if able to click on card
        getMousePosition(canvasElem, e); //on mouseclick down get x and y coordinates
    }
});

//randomize array of images
function shuffle(array){
    let index = array.length, random;
    while( index != 0) {
        random = Math.floor(Math.random()*index);
        index--;
        [array[index],array[random]] = [array[random],array[index]];
    }
    return array;
}

function flip(x,y,scaleX){
    ctx.clearRect(x-43,y,150,100);
    ctx.translate(x+23,y+50);
    //ctx.rotate(angle);
     ctx.scale(-scaleX,1);
     if(scaleX>=0){
         ctx.drawImage(mcoverup,-mcoverup.width/2,-mcoverup.height/2,180,100);
     } else {
         ctx.drawImage(flipCard,-flipCard.width/2,-flipCard.height/2,222,100);
     } ctx.setTransform(1,0,0,1,0,0);
 }

 function animate (){
     clickEnabled = false;
     flip(cardX,cardY,(scaleX/200));
     scaleX+=scaleDirection*scaleDelta;
     if(scaleX<-100 || scaleX > 100){
         scaleDirection*=-1;
         scaleX+=scaleDirection*scaleDelta;
     }
     if(scaleX > -100){
         window.setTimeout(function(){
             window.requestAnimationFrame(animate);
         },0.1);
     } else if(cardsClicked.length < 2){
         clickEnabled =true;
     }
 }

 function flip2(x,y,scaleX){
    ctx.clearRect(x-43,y,150,100);
    ctx.translate(x+23,y+50);
    //ctx.rotate(angle);
     ctx.scale(-scaleX,1);
     if(scaleX>=0){
        ctx.drawImage(flipCard,-flipCard.width/2,-flipCard.height/2,180,100);
     } else {
        ctx.drawImage(mcoverup,-mcoverup.width/2,-mcoverup.height/2,222,100);
     } ctx.setTransform(1,0,0,1,0,0);
 }

 function animate2 (){
     clickEnabled = false;
     flip2(cardX,cardY,(scaleX/200));
     scaleX+=scaleDirection*scaleDelta;
     if(scaleX<-100 || scaleX > 100){
         scaleDirection*=-1;
         scaleX+=scaleDirection*scaleDelta;
     }
     if(scaleX > -100){
         window.setTimeout(function(){
             window.requestAnimationFrame(animate2);
         },0.1);
     } else if(cardsClicked.length == 0){
        clickEnabled = true;
     }
 }
