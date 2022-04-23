#include <libchessviz/Attack.h>


int UnderAttack(int X, int Y, char Desk[][deskSide])
{
	int h = Y, v = X, WhiteAttack = 0, BlackAttack = 0;
	
	for(h += 1;h < deskSide; h++) 
		if(Desk[v][h] != ' ' && h != Y) {
			
			if(Desk[v][h] == 'R') WhiteAttack = 1;
			else if(Desk[v][h] == 'Q') WhiteAttack = 1;
			else if(Desk[v][h] == 'K' && abs(Y - h) == 1) WhiteAttack = 1;
			
			if(Desk[v][h] == 'r') BlackAttack = 1;
			else if(Desk[v][h] == 'q') BlackAttack = 1;
			else if(Desk[v][h] == 'k' && abs(Y - h) == 1) BlackAttack = 1;
			
			break; 	
		}

	h = Y; 
	v = X;
	for(h -= 1; h >= 0; h--) 
		if(Desk[v][h] != ' ' && h != Y) {		
			if(Desk[v][h] == 'R') WhiteAttack = 1;
			else if(Desk[v][h] == 'Q') WhiteAttack = 1;
			else if(Desk[v][h] == 'K' && abs(Y - h) == 1) WhiteAttack = 1;
			
		
			if(Desk[v][h] == 'r') BlackAttack = 1;
			else if(Desk[v][h] == 'q') BlackAttack = 1;
			else if(Desk[v][h] == 'k' && abs(Y - h) == 1) BlackAttack = 1;
			
			break;
		}
	
	h = Y; 
	v = X;
	for(v += 1;h < deskSide; v++) 
		if(Desk[v][h] != ' ' && v != X) {
			
			if(Desk[v][h] == 'R') WhiteAttack = 1;
			else if(Desk[v][h] == 'Q') WhiteAttack = 1;
			else if(Desk[v][h] == 'K' && abs(Y - h) == 1) WhiteAttack = 1;
			
			if(Desk[v][h] == 'r') BlackAttack = 1;
			else if(Desk[v][h] == 'q') BlackAttack = 1;
			else if(Desk[v][h] == 'k' && abs(Y - h) == 1) BlackAttack = 1;
			
			break; 	
		}

	h = Y; 
	v = X;
	for(v -= 1; v >= 0; v--) 
		if(Desk[v][h] != ' ' && v != X) {		
			if(Desk[v][h] == 'R') WhiteAttack = 1;
			else if(Desk[v][h] == 'Q') WhiteAttack = 1;
			else if(Desk[v][h] == 'K' && abs(Y - h) == 1) WhiteAttack = 1;
			
		
			if(Desk[v][h] == 'r') BlackAttack = 1;
			else if(Desk[v][h] == 'q') BlackAttack = 1;
			else if(Desk[v][h] == 'k' && abs(Y - h) == 1) BlackAttack = 1;
			
			break;
		}
	h = Y, v = X;
	while(h < deskSide && v < deskSide) {
		
		if(Desk[v][h] != ' ' && v != X && h != Y){
			if(Desk[v][h] == 'Q') WhiteAttack = 1;
			else if(Desk[v][h] == 'B') WhiteAttack = 1;
			else if(Desk[v][h] == 'P' && X - v == -1 && Y - h == -1) WhiteAttack = 1;
			else if(Desk[v][h] == 'K' && abs(X - v) == 1 && abs(Y - h) == 1) WhiteAttack = 1;
			
			if(Desk[v][h] == 'q') BlackAttack = 1;
			else if(Desk[v][h] == 'b') BlackAttack = 1;
			else if(Desk[v][h] == 'k' && abs(X - v) == 1 && abs(Y - h) == 1) BlackAttack = 1;
			
			break;	
		}
		h++; v++;
	}
	h = Y, v = X;
	while(h >= 0 && v >= 0){	
		if(Desk[v][h] != ' ' && v != X && h != Y) {
			if(Desk[v][h] == 'Q') WhiteAttack = 1;
			else if(Desk[v][h] == 'B') WhiteAttack = 1;
			else if(Desk[v][h] == 'K' && abs(X - v) == 1 && abs(Y - h) == 1) WhiteAttack = 1;
			
			if(Desk[v][h] == 'q') BlackAttack = 1;
			else if(Desk[v][h] == 'b') BlackAttack = 1;
			else if(Desk[v][h] == 'p' && X - v == 1 && Y - h == 1) BlackAttack = 1;
			else if(Desk[v][h] == 'k' && abs(X - v) == 1 && abs(Y - h) == 1) BlackAttack = 1;
			
			break;	
		}
		h--; 
		v--;
	}
	
	h = Y, v = X;
	while(h >= 0 && v < deskSide) {
		
		if(Desk[v][h] != ' ' && v != X && h != Y) {
			if(Desk[v][h] == 'Q') WhiteAttack = 1;
			else if(Desk[v][h] == 'B') WhiteAttack = 1;
			else if(Desk[v][h] == 'P' && X - v == -1 && Y - h == 1) WhiteAttack = 1;
			else if(Desk[v][h] == 'K' && abs(X - v) == 1 && abs(Y - h) == 1) WhiteAttack = 1;
			
			if(Desk[v][h] == 'q') BlackAttack = 1;
			else if(Desk[v][h] == 'b') BlackAttack = 1;
			else if(Desk[v][h] == 'k' && abs(X - v) == 1 && abs(Y - h) == 1) BlackAttack = 1;
			
			break;	
		}
		h--;
		v++;
	}
	h = Y, v = X;
	while(h < deskSide && v >= 0) {	
		if(Desk[v][h] != ' ' && v != X && h != Y){
			if(Desk[v][h] == 'Q') WhiteAttack = 1;
			else if(Desk[v][h] == 'B') WhiteAttack = 1;
			else if(Desk[v][h] == 'K' && abs(X - v) == 1 && abs(Y - h) == 1) WhiteAttack = 1;
			
			if(Desk[v][h] == 'q') BlackAttack = 1;
			else if(Desk[v][h] == 'b') BlackAttack = 1;
			else if(Desk[v][h] == 'p' && X - v == 1 && Y - h == -1) BlackAttack = 1;
			else if(Desk[v][h] == 'k' && abs(X - v) == 1 && abs(Y - h) == 1) BlackAttack = 1;
			
			break;	
		}
		h++; 
		v--;
	}
	if(X - 2 >= 0 && Y - 1 >= 0) {
		if(Desk[X - 2][Y - 1] == 'N') WhiteAttack = 1;
		else if(Desk[X - 2][Y - 1] == 'n') BlackAttack = 1;
	}
	if(X + 2 < deskSide && Y - 1 >= 0) {
		if(Desk[X + 2][Y - 1] == 'N') WhiteAttack = 1;
		else if(Desk[X + 2][Y - 1] == 'n') BlackAttack = 1;
	}
	if(X - 2 >= 0 && Y + 1 < deskSide) {
		if(Desk[X - 2][Y + 1] == 'N') WhiteAttack = 1;
		else if(Desk[X - 2][Y + 1] == 'n') BlackAttack = 1;
	}
	if(X + 2 < deskSide && Y + 1 < deskSide) {
		if(Desk[X + 2][Y + 1] == 'N') WhiteAttack = 1;
		else if(Desk[X + 2][Y + 1] == 'n') BlackAttack = 1;
	}
	
	if(X - 1 >= 0 && Y - 2 >= 0) {
		if(Desk[X - 1][Y - 2] == 'N') WhiteAttack = 1;
		else if(Desk[X - 1][Y - 2] == 'n') BlackAttack = 1;
	}
	if(X + 1 < deskSide && Y - 2 >= 0) {
		if(Desk[X + 1][Y - 2] == 'N') WhiteAttack = 1;
		else if(Desk[X + 1][Y - 2] == 'n') BlackAttack = 1;
	}
	if(X - 1 >= 0 && Y + 2 < deskSide) {
		if(Desk[X - 1][Y + 2] == 'N') WhiteAttack = 1;
		else if(Desk[X - 1][Y + 2] == 'n') BlackAttack = 1;
	}
	if(X + 1 < deskSide && Y + 2 < deskSide) {
		if(Desk[X + 1][Y + 2] == 'N') WhiteAttack = 1;
		else if(Desk[X + 1][Y + 2] == 'n') BlackAttack = 1;
	}
	if(BlackAttack == 0) return WhiteAttack;
	if(WhiteAttack == 0) return -BlackAttack;
	return WhiteAttack + BlackAttack;
}

int* FindFigure(char Figure, char Desk[][deskSide])
{
	
	int i, j;
	int* Cord = (int*)malloc(sizeof(int)*2); 
	Cord[0] = Cord[1] = -1;
	
	for(i = 0; i < deskSide; i++) {
		for(j = 0; j < deskSide; j++) {
			if(Desk[i][j] == Figure) {
				Cord[0] = i;
				Cord[1] = j;
				return Cord;
			}
		}
	}
	return Cord;
}


int KingUnderAttack(int Color, char Desk[][deskSide])
{
	int *King = (int*)malloc(sizeof(int)*2);
	King[0] = FindFigure('K', Desk)[0];
	King[1] = FindFigure('K', Desk)[1];	
	if(Color == 1) {	
		if(UnderAttack(King[0], King[1], Desk) == -Color || UnderAttack(King[0], King[1], Desk) == 2) return 1;
	} else {
		King[0] = FindFigure('k', Desk)[0];
		King[1] = FindFigure('k', Desk)[1];
		if(UnderAttack(King[0], King[1], Desk) == -Color || UnderAttack(King[0], King[1], Desk) == 2) return 1;
	}
	free(King);
	return 0;
}
