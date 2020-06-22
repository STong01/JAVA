x = linspace(-3.8,3.8);
y_cos = cos(x);
y_poly = 1 - x.^2./2 + x.^4./24;

subplot(2,2,1);
plot(x,y_cos);
title('Subplot 1: Cosine')

subplot(2,2,2);
plot(x,y_poly,'g');
title('Subplot 2: Polynomial')

subplot(2,2,[3,4]);
plot(x,y_cos,'b',x,y_poly,'g');
title('Subplot 3 and 4: Both')
