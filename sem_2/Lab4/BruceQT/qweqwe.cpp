struct st{int x; int y;};
int abs(int x){
	if (x < 0){
		x*=-1;
	}
	return x;
}
double abs(double y){
	if (y < 0){
		y *= -1;
	}
	return y;
}
float abs(float x){
	if (x < 0){
		x *= -1;
	}
	return x;
}
