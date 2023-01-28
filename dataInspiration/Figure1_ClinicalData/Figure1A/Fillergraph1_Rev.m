% Guido_Filler Figures
% First round of edits
% June 11, 2018 AK
% Inputs: 2 column data file with col1 = days, col2 = systolic BP. (Note: where was this systolic BP measured - in LV or or arm)
% Outputs: figure with raw data, running average.

clear all
clear all
close all
close all

% Original Figure
% [v,T,vT]=xlsread('GuidoFillerFig1_toDigitize.xlsx'); % import data saved from engauge digitizer
%
wid = 4;
fs = 18;
%
%
rawData = load('digitizedTextData.txt');
t	=	rawData(:,1);
y	=	rawData(:,2);
%
h = figure('rend','painters','pos', [1 1 1100 600]);
plot(t,y,'o-','LineWidth', wid , 'markersize', 10,'Color', [0.5 0.5 0.5]);
% set(gcf, 'Units', 'Normalized', 'OuterPosition', [0 0 1 1]); % Enlarge figure to full screen.
% title('Systolic BP');
xlabel('days', 'FontSize', fs);
ylabel('systolic BP, mmHg', 'FontSize', fs);
box off;
xticks([0 4 10 13 20 23]);
yticks([70 110 150]);
set(gca, 'FontSize', 24);
axis([-0.1 23 70 155]);

hold on;

M = movmean(y, 8); 
plot(t,M, 'LineWidth', wid, 'Color', 'red');
hold on
y2 = 100;
line([0,23],[y2,y2], 'LineWidth',wid,'Color','black', 'LineStyle','--');
box off;

line([0,23],[y2,y2], 'Color','green','LineWidth',wid, 'LineStyle','--');
hold on
x3 = 4;
line([x3,x3],[70,148],'Color','black', 'Linestyle', '--', 'LineWidth', wid);
hold on
x4 = 13;
line([x4,x4],[70,148],'Color', 'black', 'Linestyle', '--', 'LineWidth', wid);

set(gca,'TickDir','out'); % The only other option is 'in'

lgd.FontSize 	= 12;
txt1 			= 'start PD';
text(2,151,txt1, 'Fontsize', fs);
txt2 		= 'stop PD';
text(11.5,151,txt2, 'Fontsize', fs);
legend('clinical', 'running avg.','Location','NorthEast');
legend boxoff;

ax = gca;
ax.LineWidth = wid;
ax.TickDir = 'out';

set(gca,'FontSize',20); % this is almost global.
set(gca,'linewidth',3); % this is global.

saveas(gca,'Figure1_averagedBP.jpg');


