%
% Guido Filler paper.
close all
close all
clear all
clear all
%
%
wid = 5;
fs = 34;
%
% Weight graph
y = [3.9, 4.1, 4.85, 6.262]; % mass (kg) 
h = figure('rend','painters','pos',[1 1 1300 550]);
b = bar(y,0.4,'black');
name = {'0', '30', '47', '138'}; % infant age in days
set(gca,'xticklabel',name, 'FontSize', 24)
xlabel('age (days)', 'FontSize', 30);
ylabel('weight (kg)', 'FontSize', 30);
% title('A', 'FontSize', 30);
xlim([0.5 4.5]);
ylim([0 6.75]);
yticks([0 2 6]);
box off
txt2 		= 'A';
text(0.45, 7.1,txt2, 'Fontsize', 24);
set(gca,'TickDir','out'); % The only other option is 'in'
%
ax = gca;
ax.LineWidth = wid;
ax.TickDir = 'out';
%
saveas(h,sprintf('FigureA_weight.png'))

clear all;
clear all;

wid = 5;
fs = 34;

% Heart Rate graph
% subplot(1,2,2,'Parent',p) 
h = figure('rend','painters','pos',[1 1 1300 550]);
y1 = [110, 150, 144, 147]; % heart rate
% f = figure('units','normalized','outerposition',[0 0 1 1]);
b = bar(y1,0.4,'black');
name = {'0', '30', '47', '138'}; % infant age in days
set(gca,'xticklabel',name, 'FontSize', 30)
xlabel('age (days)', 'FontSize', 24);
ylabel('heart rate (bpm)', 'FontSize', 30);
% title('B', 'FontSize', 28);
xlim([0.5 4.5]);
ylim([100 160]);
yticks([80 120 155]);
box off
txt2 		= 'B';
text(0.45, 162.5,txt2, 'Fontsize', 24);
ax = gca;
ax.LineWidth = wid;
ax.TickDir = 'out';
saveas(h,sprintf('FigureB_hr.png'))




