PROCEDURE Main is
-- Our first ADA program!
	a,b,c:INTEGER;
	x,y:FLOAT;
	PROCEDURE One(IN m:INTEGER; OUT n:INTEGER) is
	BEGIN
		m := n * 2;
	END One;
BEGIN
	a := 42;
	One(a,b);
	x := 42.0;
	y := x + 10.0;
END Main;