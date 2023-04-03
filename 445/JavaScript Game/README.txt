Some nifty features of our program that were tough to implement were randomizing the card images on each game reset. We had to do some pixel math to make sure the cards stayed in the same spot on every refresh. 
Another hard aspect was creating the flipping card animation.In order to get the cards to flip we had to scale the x aspect of the card down and continuously redraw the card until it was only a line. Then switch the image and scale the x back up for the new image and redraw it until it was the original value.


