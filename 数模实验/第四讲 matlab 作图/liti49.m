t = 0 : 0.1 : 1.0
[X,Y,Z] = cylinder(t);

subplot(2,2,1); surf(X,Y,Z);view(-37.5,30)
subplot(2,2,2);surf(X,Y,Z);view(0,90)
subplot(2,2,3);surf(X,Y,Z);view(-60,35) 
subplot(2,2,4);surf(X,Y,Z);view([1,0,0])
