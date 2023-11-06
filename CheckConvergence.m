function conv_result = CheckConvergence(err_table, k, l2ord, h1ord, vord, tol)
% Check convergence rates of last k element of err_table.
% Returns true if conv rates of last k errors are l2ord, h1ord, vord,
% within a certain tolerance.
l2rates = diff(log(err_table.L2errors))./diff(log(err_table.H));
h1rates = diff(log(err_table.H1errors))./diff(log(err_table.H));
vrates = diff(log(err_table.Verrors))./diff(log(err_table.H));
conv_result = false;
rates_check = [sum(abs(l2rates(end-k:end) - l2ord)./l2ord)/k < tol, ...
    sum(abs(h1rates(end-k:end) - h1ord)./h1ord)/k < tol, ...
    sum(abs(vrates(end-k:end) - vord)./vord)/k < tol];
if all(rates_check, 'all')
    conv_result = true;
end
end