1. The code creates 5 columns with all of them having the space divided evenly. The 1fr divides the space for each column evenly. 

2. The header and footer take up all of the columns since the span 5 in the grid-column has them go across 5 columns. The main only spans 3 columns and the aside only spans 2 columns as well which is why they are next to each other.

3. $("#gameEndBox").fadeIn("slow", function(){
			$("#gameEndBox").animate({backgroundColor:'#4E1402'},2000,function(){
				$("#gameEndBox").css("background-color","cyan").fadeTo("slow",0.11).slideUp(1000).slideDown(1000,function(){
					$("#gameEndBox").css("background-color","transparent");
				});
			});
		});

	The Callback for my end game is that it fades then after that the callback is that it animates the color then the callback goes to the chaining part. 
	The chaining for my program is that it changes the backgound color than it fades the color then it slides up then slides down. 
	It then calls for the background color to be transparent as a final callback.