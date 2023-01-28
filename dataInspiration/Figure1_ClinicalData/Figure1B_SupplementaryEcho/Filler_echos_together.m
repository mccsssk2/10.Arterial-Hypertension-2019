% SRK July 3, 2018.
%
% Code to plot segmented aortic root diameter measurements.
% 
% Inputs: txt files for the 4 echos, each with 4 diameter measurements.
% Output: Colour coded figure.
%
%
clear all
clear all
close all
close all
%
%
wid = 5;
fs = 20;
dx = 0.075; % mm.
%
%
% Finding means 
load first_echo_measurements.txt; %  read data in 
time1 = first_echo_measurements(:,1);
one1 = first_echo_measurements(:,2);    	M11 	= mean(one1);
two1 = first_echo_measurements(:,3);   	M12 	= mean(two1);
three1 = first_echo_measurements(:,4); 	M13 	= mean(three1);
four1 = first_echo_measurements(:,5);    	M14 	= mean(four1);

load second_echo_measurements.txt; %  read data in 
time2 = second_echo_measurements(:,1);
one2 = second_echo_measurements(:,2);  	M21 	= mean(one2);
two2 = second_echo_measurements(:,3);	 	M22 	= mean(two2);
three2 = second_echo_measurements(:,4); 	M23 	= mean(three2);
four2 = second_echo_measurements(:,5); 	M24 	= mean(four2);

load third_echo_measurements.txt; %  read data in 
time3 = third_echo_measurements(:,1);
one3 = third_echo_measurements(:,2);
M31 = mean(one3);
two3 = third_echo_measurements(:,3);
M32 = mean(two3);
three3 = third_echo_measurements(:,4);
M33 = mean(three3);
four3 = third_echo_measurements(:,5);
M34 = mean(four3);

load fourth_echo_measurements.txt; %  read data in 
time4 = fourth_echo_measurements(:,1);
one4 = fourth_echo_measurements(:,2);    
M41 = mean(one4);
two4 = fourth_echo_measurements(:,3);
M42 = mean(two4);
three4 = fourth_echo_measurements(:,4);
M43 = mean(three4);
four4 = fourth_echo_measurements(:,5);
M44 = mean(four4);

% Creating bar graph
h = figure('rend','painters','pos',[1 1 1200 800]);
y = [M11 M21 M31 M41; M12 M22 M32 M42; M13 M23 M33 M43; M14 M24 M34 M44] * dx; % now in mm.
b = bar(y,0.5, 'EdgeColor', 'none');
b(1).FaceColor = [1 0 0];
b(2).FaceColor = [0.5 0 0.5];
b(3).FaceColor = [0.4 0 0];
b(4).FaceColor = [0 0.5 0];
% name = {'outflow tract'; 'sinuses of valsalva'; 'sinotub. jn.'; 'tub. ascending aorta'};
name = {''};
ylabel({'ascending aorta' 'diameters (mm)'}, 'FontSize', fs);
% title('ascending aorta diameters', 'FontSize', fs);
LEG = legend('day 1', 'month 1', 'month 2', 'month 5','Location','northwest');
yticks([0 5 10]);
axis([0.5 4.5 0 11]);
legend boxoff;
box off;
LEG.FontSize = fs;
% txt2 		= 'B';
% text(0.45, 11.5, txt2, 'Fontsize', fs);
set(gca,'TickDir','out'); % The only other option is 'in'
set(gca,'xticklabel',name);
txt = {'outflow'; 'tract (1)'};
text(0.75, -0.75, txt, 'FontSize', 20);
txt = {'sinus of'; 'valsalva (2)'};
text(1.75, -0.75, txt, 'FontSize', 20);
txt = {'sino-tubular'; 'junction (3)'};
text(2.75, -0.75, txt, 'FontSize', 20);
txt = {'tubular'; ' ascending aorta (4)'};
text(3.75, -0.75, txt, 'FontSize', 20);

set(gca,'TickDir','out'); 
set(gca,'xtick',[]);

set(gca,'FontSize',20); % this is almost global.
set(gca,'linewidth',3); % this is global.
% saveas(h,sprintf('Guido_Figure2_Aortic_measurements.jpg'));
saveas(gca, 'Guido_Figure2_Aortic_measurementsPart.png');
% return;
%
% 
%
% Plot the time series for supplement.
h = figure('rend','painters','pos', [1 1 1100 600]);
lw = 10;
fs = 34;
% plot(first_echo_measurements(:,1), first_echo_measurements(:,2), first_echo_measurements(:,1), first_echo_measurements(:,3), first_echo_measurements(:,1), first_echo_measurements(:,4), first_echo_measurements(:,1), first_echo_measurements(:,5), 'LineWidth', 3 );
% plot(first_echo_measurements(:,2), second_echo_measurements(1:9,2), third_echo_measurements(1:9,2), fourth_echo_measurements(1:9,2), 'LineWidth', 5 );
plot(first_echo_measurements(:,2),'-r', 'LineWidth', lw); 									hold on;
plot(second_echo_measurements(:,2),'Color',  [0.4940, 0.1840, 0.5560]  , 'LineWidth', lw); 	hold on;
plot(third_echo_measurements(:,2),'Color', [0.6350, 0.0780, 0.1840] , 'LineWidth', lw); 		hold on;
plot(fourth_echo_measurements(:,2),'Color', [0 0.5 0] , 'LineWidth', lw);
set(gca,'xtick',[]);
set(gca,'xticklabel',[]);
xlabel('time (one heart beat)', 'FontSize', fs);
ylabel('diamters (pixels)', 'FontSize', fs);
% title('outflow tract', 'FontSize', fs);
txt1 = 'outflow tract';
text(4,130,txt1, 'Fontsize', fs);
legend('day 1', 'month 1', 'month 2', 'month 5','Location','northwest');
set(gca, 'FontSize', fs);
axis([1 9 40 150]);
yticks([40 70 100 140]);
legend boxoff;
box off;
txt2 		= 'A';
text(1, 155, txt2, 'Fontsize', fs);
ax = gca;
ax.LineWidth = wid;
ax.TickDir = 'out';

set(gca,'TickDir','out'); % The only other option is 'in'
set(gca,'FontSize',20); % this is almost global.
set(gca,'linewidth',5); % this is global.

saveas(h,sprintf('FigS2_A_outflowTract_PanelA.png'))
%
%
%
h = figure('rend','painters','pos', [1 1 1100 600]);
plot(first_echo_measurements(:,3),'-r', 'LineWidth', lw ); 									hold on;
plot(second_echo_measurements(:,3),'Color',  [0.4940, 0.1840, 0.5560]  , 'LineWidth', lw ); 	hold on;
plot(third_echo_measurements(:,3),'Color', [0.6350, 0.0780, 0.1840] , 'LineWidth', lw ); 		hold on;
plot(fourth_echo_measurements(:,3),'Color', [0 0.5 0] , 'LineWidth', lw );
set(gca,'xtick',[]);
set(gca,'xticklabel',[]);
xlabel('time (one heart beat)', 'FontSize', fs);
ylabel('diamters (pixels)', 'FontSize', fs);
% title('sinuses of valsalva', 'FontSize', fs);
txt1 = 'sinuses of valsalva';
text(2.5,130,txt1, 'Fontsize', fs);
% legend('day 1', 'month 1', 'month 2', 'month 5','Location','northwest');
set(gca, 'FontSize', fs);
legend boxoff;
box off;
axis([1 9 40 150]);
yticks([40 70 100 140]);
txt2 		= 'B';
text(1, 155, txt2, 'Fontsize', 34);
set(gca,'TickDir','out'); % The only other option is 'in'
ax = gca;
ax.LineWidth = wid;
ax.TickDir = 'out';

set(gca,'TickDir','out'); % The only other option is 'in'
set(gca,'FontSize',20); % this is almost global.
set(gca,'linewidth',5); % this is global.


saveas(h,sprintf('FigS2_B_valsalva_PanelB.png'))
%
%
h = figure('rend','painters','pos', [1 1 1100 600]);
plot(first_echo_measurements(:,4),'-r', 'LineWidth', lw); 									hold on;
plot(second_echo_measurements(:,4),'Color',  [0.4940, 0.1840, 0.5560]  , 'LineWidth', lw ); 	hold on;
plot(third_echo_measurements(:,4),'Color', [0.6350, 0.0780, 0.1840] , 'LineWidth', lw ); 		hold on;
plot(fourth_echo_measurements(:,4),'Color', [0 0.5 0] , 'LineWidth', lw );
set(gca,'xtick',[]);
set(gca,'xticklabel',[]);
xlabel('time (one heart beat)', 'FontSize', fs);
ylabel('diamters (pixels)', 'FontSize', fs);
% title('sinotubular jn.', 'FontSize', fs);
txt1 = 'sinotubular jn.';
text(3,130,txt1, 'Fontsize', fs);

% legend('day 1', 'month 1', 'month 2', 'month 5','Location','northwest');
set(gca, 'FontSize', fs);
legend boxoff;
box off;
axis([1 9 40 150]);
yticks([40 70 100 140]);
txt2 		= 'C';
text(1, 155, txt2, 'Fontsize', 34);
set(gca,'TickDir','out'); % The only other option is 'in'
ax = gca;
ax.LineWidth = wid;
ax.TickDir = 'out';

set(gca,'TickDir','out'); % The only other option is 'in'
set(gca,'FontSize',20); % this is almost global.
set(gca,'linewidth',5); % this is global.


saveas(h,sprintf('FigS2_C_vasalva_PanelC.png'))
%
%
%
h = figure('rend','painters','pos', [1 1 1100 600]);
plot(first_echo_measurements(:,5),'-r', 'LineWidth', lw); 									hold on;
plot(second_echo_measurements(:,5),'Color',  [0.4940, 0.1840, 0.5560]  , 'LineWidth', lw ); 	hold on;
plot(third_echo_measurements(:,5),'Color', [0.6350, 0.0780, 0.1840] , 'LineWidth', lw ); 		hold on;
plot(fourth_echo_measurements(:,5),'Color', [0 0.5 0] , 'LineWidth', lw );
set(gca,'xtick',[]);
set(gca,'xticklabel',[]);
xlabel('time (one heart beat)', 'FontSize', fs);
ylabel('diamters (pixels)', 'FontSize', fs);
% title('tubular ascending aorta diameter', 'FontSize', fs);
txt1 = 'tubular ascending aorta';
text(3,60,txt1, 'Fontsize', fs);

% legend('day 1', 'month 1', 'month 2', 'month 5','Location','northwest');
set(gca, 'FontSize', fs);
legend boxoff;
box off;
axis([1 9 40 150]);
yticks([40 70 100 140]);
txt2 		= 'D';
text(1, 155, txt2, 'Fontsize', 34);
set(gca,'TickDir','out'); % The only other option is 'in'
ax = gca;
ax.LineWidth = wid;
ax.TickDir = 'out';

set(gca,'TickDir','out'); % The only other option is 'in'
set(gca,'FontSize',20); % this is almost global.
set(gca,'linewidth',5); % this is global.


saveas(h,sprintf('FigS2_D_tubularAscending_PanelD.png'))
%
return;


