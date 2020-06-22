n=30;
[x,y,z]=sphere(30);
m=moviein(n);
for i=1:n
   surf(i*x,i*y,i*z)
   m(:,i)=getframe;
end
movie(m)
