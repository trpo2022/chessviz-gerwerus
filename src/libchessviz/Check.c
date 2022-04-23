#include <libchessviz/Check.h>

Right CheckPawn(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;
    if (H0 == H1) {
        if (Desk[V1][H1] != ' ') {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if ((V0 - V1) * Color > 2 || (V0 - V1) * Color < 0) {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if ((V0 - V1) * Color == 2
            && (V0 != (deskSide - 1 - 1 * Color) % (deskSide - 1)
                || Desk[V0 - Color][H0] != ' ')) {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if (MoveType != '-') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
        };
    } else {
        if (H1 - H0 != 1 && H0 - H1 != 1) {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if ((V0 - V1) * Color != 1) {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if (Desk[V1][H1] == ' ') {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if (Color == IsUpper(Desk[V1][H1])) {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if (MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
        };
    }
    right.Code = 0;
    right.Rokirovka = 0;
    strcpy(right.Error, "");
    return right;
}




Right CheckKing(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;
    
    
    if(abs(V1 - V0) > 1 || abs(H1 - H0) > 1) {
            right.Code = 1;
            strcpy(right.Error, "King can't move like that");
            return right;
    };
	if(abs(V1 - V0) == 0 && abs(H1 - H0) == 0) {
            right.Code = 1;
            strcpy(right.Error, "King can't move like that");
            return right;
    };
	if(Desk[V1][H1] != ' ') {
		if(Color == IsUpper(Desk[V1][H1]))  {
            right.Code = 1;
            strcpy(right.Error, "King can't move like that");
            return right;
    	}
		else if(MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
    	}
    }
    right.Code = 0;
    right.Rokirovka = 1;
    strcpy(right.Error, "");
    return right;
}

Right CheckKnight(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;
      
    if(abs(V1 - V0) + abs(H1 - H0) != 3) {
        right.Code = 1;
        strcpy(right.Error, "Knight can't move like that");
        return right;
	}
	if(abs(V1 - V0) == 0 || abs(H1 - H0) == 0) {
        right.Code = 1;
        strcpy(right.Error, "Knight can't move like that");
        return right;
	}
    
	if(Desk[V1][H1] != ' ') {
		if(Color == IsUpper(Desk[V1][H1]))  {
            right.Code = 1;
            strcpy(right.Error, "Knight can't move like that");
            return right;
    	}
		else if(MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
    	}
    }
    
    right.Code = 0;
    right.Rokirovka = 0;
    strcpy(right.Error, "");
    return right;
}


Right CheckQueen(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;
    
    if(H0 == H1 || V0 == V1) {
		if(RookCollision(H0, V0, H1, V1, Desk) == -1) {
            right.Code = 1;
            strcpy(right.Error, "Queen can't move like that");
            return right;
    	}
	}
	else if(abs(H0 - H1) == abs(V0 - V1)) {	
		if(BishopCollision(H0, V0, H1, V1, Desk) == -1) {
            right.Code = 1;
            strcpy(right.Error, "Queen can't move like that");
            return right;
    	}
	}
	else {
        right.Code = 1;
        strcpy(right.Error, "Queen can't move like that");
        return right;
    }
	
	if(Desk[V1][H1] != ' ') {
		if(Color == IsUpper(Desk[V1][H1])) {
            right.Code = 1;
            strcpy(right.Error, "Queen can't move like that");
            return right;
    	}
		else if(MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
    	}
    }
    
    right.Code = 0;
    right.Rokirovka = 0;
    strcpy(right.Error, "");
    return right;
}


Right CheckRook(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;
    
    if(H0 == H1 || V0 == V1) {
		if(RookCollision(H0, V0, H1, V1, Desk) == -1) {
            right.Code = 1;
            strcpy(right.Error, "Rook can't move like that");
            return right;
    	}
	}
	else {
        right.Code = 1;
        strcpy(right.Error, "Rook can't move like that");
        return right;
    }
	
	if(Desk[V1][H1] != ' ') {
		if(Color == IsUpper(Desk[V1][H1])) {
            right.Code = 1;
            strcpy(right.Error, "Rook can't move like that");
            return right;
    	}
		else if(MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
    	}
    }
    
    right.Code = 0;
    right.Rokirovka = 0;
    strcpy(right.Error, "");
    return right;
}

Right CheckBishop(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;
    
	if(abs(H0 - H1) == abs(V0 - V1)) {	
		if(BishopCollision(H0, V0, H1, V1, Desk) == -1) {
            right.Code = 1;
            strcpy(right.Error, "Queen can't move like that");
            return right;
    	}
	}
	else {
        right.Code = 1;
        strcpy(right.Error, "Queen can't move like that");
        return right;
    }
	
	if(Desk[V1][H1] != ' ') {
		if(Color == IsUpper(Desk[V1][H1])) {
            right.Code = 1;
            strcpy(right.Error, "Queen can't move like that");
            return right;
    	}
		else if(MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
    	}
    }
    
    right.Code = 0;
    right.Rokirovka = 0;
    strcpy(right.Error, "");
    return right;
}



//Right GetRight(char Figure, Move move, char Desk[deskSide][deskSide]){
//	int Color;
//	int H0, H1, V0, V1;
//	char MoveType;
//	H0 = move.H0;
//	H1 = move.H1;
//	V0 = move.V0;
//	V1 = move.V1;
//	MoveType = move.MoveType;
//	Right right;
//	
//	if(H0 < 0 || H1 < 0 || V0 < 0 || V1 < 0){
//		right.Code = 1;
//		strcpy(right.Error, "Can't get coordinats");
//		return right;
//	}
//	
//	if(Desk[V0][H0] != Figure){
//		right.Code = 1;
//		strcpy(right.Error, "Different figure");
//		return right;		
//	}
//	
//	if(V0 == V1 && H0 == H1){
//		right.Code = 1;
//		strcpy(right.Error, "You don't make a move");
//		return right;
//	};
//	
////	if(Figure == 'P' || Figure == 'p'){
////		right = CheckPawn(H0, H1, V0, V1, MoveType, Figure, Desk);
////		return right;
////	}
////	else if(Figure == 'K' || Figure == 'k'){
////		Color = IsUpper(Figure);
////
////		if(abs(V1 - V0) > 1 || abs(H1 - H0) > 1) Exit("King can't move like that");
////		if(abs(V1 - V0) == 0 && abs(H1 - H0) == 0) Exit("King can't move like that");
////		if(Desk[V1][H1] != ' ')
////			if(Color == IsUpper(Desk[V1][H1])) Exit("King can't move like that");
////			else if(MoveType != 'x') Exit("Wrong Move Type");
////		King Move bool rokirovka
//	}
//	else if(Figure == 'N' || Figure == 'n'){
//		Color = IsUpper(Figure);
//		if(abs(V1 - V0) + abs(H1 - H0) != 3) Exit("Knight can't move like that");
//		if(abs(V1 - V0) == 0 || abs(H1 - H0) == 0) Exit("Knight can't move like that");
//		if(Desk[V1][H1] != ' ')
//			if(Color == IsUpper(Desk[V1][H1])) Exit("Knight can't move like that");
//			else if(MoveType != 'x') Exit("Wrong Move Type");	
//	}
//	else if(Figure == 'Q' || Figure == 'q'){
//		Color = IsUpper(Figure);
//		
//		if(H0 == H1 || V0 == V1){
//			if(RookCollision(H0, V0, H1, V1, Desk) == -1) Exit("Queen can't move like that");
//		}
//		else if(abs(H0 - H1) == abs(V0 - V1)){	
//			if(BishopCollision(H0, V0, H1, V1, Desk) == -1) Exit("Queen can't move like that");
//		}
//		else Exit("Queen can't move like that");
//		
//		if(Desk[V1][H1] != ' ')
//			if(Color == IsUpper(Desk[V1][H1])) Exit("Queen can't move like that");
//			else if(MoveType != 'x') Exit("Wrong Move Type");
//	}
//	else if(Figure == 'R' || Figure == 'r'){
//		Color = IsUpper(Figure);
//		
//		if(H0 == H1 || V0 == V1){
//			if(RookCollision(H0, V0, H1, V1, Desk) == -1) Exit("Rook can't move like that");
//		}
//		else Exit("Rook can't move like that");
//		
//		if(Desk[V1][H1] != ' ')
//			if(Color == IsUpper(Desk[V1][H1])) Exit("Rook can't move like that");
//			else if(MoveType != 'x') Exit("Wrong Move Type");
//	}
//	else if(Figure == 'B' || Figure == 'b'){
//		Color = IsUpper(Figure);
//
//		if(abs(H0 - H1) == abs(V0 - V1)){	
//			if(BishopCollision(H0, V0, H1, V1, Desk) == -1) Exit("Bishop can't move like that");
//		}
//		else Exit("Bishop can't move like that");
//		
//		if(Desk[V1][H1] != ' ')
//			if(Color == IsUpper(Desk[V1][H1])) Exit("Bishop can't move like that");
//			else if(MoveType != 'x') Exit("Wrong Move Type");
//	}
//	right.Code = 0;
//	strcpy(right.Error, "---");
//	return right;
//}
