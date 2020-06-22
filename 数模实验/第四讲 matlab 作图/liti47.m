x=rand(1,10);
y=rand(1,10);
z=x.^2+y.^2;
scatter3(x,y,z,'ro')
hold on
[X,Y]=meshgrid(0:0.1:1);
Z=X.^2+Y.^2;
mesh(X,Y,Z)

