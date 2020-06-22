z=peaks;
subplot(1,2,1)
contour(z)
subplot(1,2,2)
[c,h]=contour(z,[0.8 1.5]);
clabel(c,h)