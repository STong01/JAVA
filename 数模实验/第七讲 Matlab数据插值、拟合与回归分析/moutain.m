x=1200:400:4000;
y=1200:400:3600;
z=[1130  1250  1280  1230  1040   900   500   700;
      1320  1450  1420  1400  1300   700   900   850;
      1390  1500  1500  1400   900  1100  1060   950;
      1500	1200  1100  1350  1450  1200  1150  1010;
      1500	1200  1100  1550  1600  1550  1380  1070;
      1500	1550  1600  1550  1600  1600  1600  1550;
     1480	1500  1550  1510  1430  1300  1200  980];
  figure(1)
  meshz(x,y,z)
  xlabel('X'),ylabel('Y'),zlabel('Z')
  
  xi=1200:50:4000;
  yi=1200:50:3600;
  

z1i=interp2(x,y,z,xi',yi,'nearest');
figure(2)
surfc(xi,yi,z1i)
title('nearest')
xlabel('X'),ylabel('Y'),zlabel('Z')


z2i=interp2(x,y,z,xi',yi);
figure(3)
surfc(xi,yi,z2i)
title('linear')
xlabel('X'),ylabel('Y'),zlabel('Z')


z3i=interp2(x,y,z,xi',yi,'cubic');
figure(4)
surfc(xi,yi,z3i)
title('cubic')
xlabel('X'),ylabel('Y'),zlabel('Z')


figure(5)
subplot(1,3,1),contour(xi,yi,z1i,10,'r');title('contour of nearest');
subplot(1,3,2),contour(xi,yi,z2i,10,'r');title('contour of linear')
subplot(1,3,3),contour(xi,yi,z3i,10,'r');title('contour of cubic')
