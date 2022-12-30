clear; clc; close all

folderName = {'Trial03','Trial05','Trial06','Trial07','Trial08','Trial09','Trial10'};

for i = 1:length(folderName)
load([folderName{i},'/tau_J_d_prime.mat']);
load([folderName{i},'/tau_J_d.mat']);
load([folderName{i},'/gamma.mat']);

figure
plot(tau_J_d_prime(1,:),tau_J_d_prime(i+1,:))
hold on
plot(tau_J_d(1,:),tau_J_d(i+1,:))
% plot(gamma(1,:),gamma(i+1,:))
end