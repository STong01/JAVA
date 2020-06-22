hours=1:12;
temps=[5 8 9 15 25 29 31 30 22 25 27 24];
h=1:0.1:12;
t=interp1(hours,temps,h,'spline');
 %直接输出数据将是很多的
plot(hours,temps,'+',h,t) 
%作图
xlabel('Hour'),ylabel('Degrees Celsius')
