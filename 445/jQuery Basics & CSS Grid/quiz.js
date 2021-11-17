var question = 0;
var questionSelected = false;
var guess = false;
var questionsAnswerd = [];
var correct = "That is correct";
var wrong = "This is wrong";
var perkQ = "Tranzit was the first map to have Double Tap 2.0"; //true
var wonderQ = "There are 3 wonder weapons in Origins" //false
var mapQ = "Nacht der Untoten has be remade 4 times" //true
var storyQ = "On Gorod Krovi the goal is to kill Dempsy 1.0" //false

$(function(){
	$("#question > p").hide()
	$("#answerBox > p").hide();
});

function showQuestion(questionPicked) {
	$("#answerBox > p").hide();
	question = questionPicked;
	if(questionsAnswerd.includes(question)){
		alert("You've already attempted this!");
		return;
	} 
	if (questionSelected){
		alert("You must answer the current question");
		return;
	}
	$("input").prop('checked',false);
	questionSelected = true;
	questionsAnswerd.push(question);
	$("#question > p").show()
	if (question == 1) {$("#question > p").text(perkQ);}
	if (question == 2) {$("#question > p").text(wonderQ);}
	if (question == 3) {$("#question > p").text(mapQ);}
	if (question == 4) {$("#question > p").text(storyQ);}

}

function enableCheck(){
	$("#checkAnswer").prop('disabled',false);
}

function checkAnswer(){
	guess = $('input[name="answer"]:checked').val();
	if (question == 1) {
		$("aside ul").append('<li id="perk">Perks</li>');
		$("#B0").prop('disabled',true);
		if(guess == "true"){
			$("#answerBox > p").text(correct);
			$("#answerBox > p").css("color","green");
			$("#answerBox > p").show();
			$("#perk").css("color","green");
		} else if(guess == "false"){
			$("#answerBox > p").text(wrong);
			$("#answerBox > p").css("color","red");
			$("#answerBox > p").show();
			$("#perk").css("color","red");
		}
	}
	if (question == 2) {
		$("aside ul").append('<li id="ww">Wonder Weapons</li>');
		$("#B1").prop('disabled',true);
		if(guess == "false"){
			$("#answerBox > p").text(correct);
			$("#answerBox > p").css("color","green");
			$("#answerBox > p").show();
			$("#ww").css("color","green");
		} else if(guess == "true"){
			$("#answerBox > p").text(wrong);
			$("#answerBox > p").css("color","red");
			$("#answerBox > p").show();
			$("#ww").css("color","red");
		}
	}
	if (question == 3) {
		$("aside ul").append('<li id="maps">Maps</li>');
		$("#B2").prop('disabled',true);
		if(guess == "true"){
			$("#answerBox > p").text(correct);
			$("#answerBox > p").css("color","green");
			$("#answerBox > p").show();
			$("#maps").css("color","green");
		} else if(guess == "false"){
			$("#answerBox > p").text(wrong);
			$("#answerBox > p").css("color","red");
			$("#answerBox > p").show();
			$("#maps").css("color","red");
		}
	}
	if (question == 4) {
		$("aside ul").append('<li id="story">Story</li>');
		$("#B3").prop('disabled',true);
		if(guess == "false"){
			$("#answerBox > p").text(correct);
			$("#answerBox > p").css("color","green");
			$("#answerBox > p").show();
			$("#story").css("color","green");
		} else if(guess == "true"){
			$("#answerBox > p").text(wrong);
			$("#answerBox > p").css("color","red");
			$("#answerBox > p").show();
			$("#story").css("color","red");
		}
	}
	if (question == 0){
		alert("You must choose a question");
		return;
	}
	questionSelected = false;
	$("#checkAnswer").prop('disabled',true);
	checkGameOver();
}

function checkGameOver(){
	if (questionsAnswerd.length == 4) {
		$("#gameEndBox").fadeIn("slow", function(){
			$("#gameEndBox").animate({backgroundColor:'#4E1402'},2000,function(){
				$("#gameEndBox").css("background-color","cyan").fadeTo("slow",0.11).slideUp(1000).slideDown(1000,function(){
					$("#gameEndBox").css("background-color","transparent");
				});
			});
		});
	}
}