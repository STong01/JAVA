t = 0:pi/10:2*pi;
[X,Y,Z] = cylinder(2+cos(t));
surf(X,Y,Z)
subplot(4,2,1); surf(X,Y,Z);view(-37.5,30)
subplot(4,2,2);surf(X,Y,Z);view(0,90)
subplot(4,2,3);surf(X,Y,Z);view(-60,35) 
subplot(4,2,4);surf(X,Y,Z);view([1,0,0])
hold on
[x,y,z] = cylinder(t);
subplot(4,2,5); surf(x,y,z);view(-37.5,30)
subplot(4,2,6);surf(x,y,z);view(0,90)
subplot(4,2,7);surf(x,y,z);view(-60,35) 
subplot(4,2,8);surf(x,y,z);view([1,0,0])
