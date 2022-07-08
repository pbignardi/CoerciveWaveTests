function [] = animate(X, T, U)
    % Animate function
    %   Function to plot a 2 variable function, in moving 
    %   time variable t.
    
    %% Parameters
    % Frame rate
    delay = 1/30;
    
    % U_lims
    u_min = min(min(U));
    u_max = max(max(U));

    % x_lims 
    x_min = min(min(X));
    x_max = max(max(X));

    % The number of time steps is given by the number of rows of U
    n_tsteps = size(U,1);

    %% Plotting
    % Plot each row of U
    for i = 1:n_tsteps
        x = X(i, :);
        u = U(i, :);
        plot(x, u);
        axis([x_min x_max u_min u_max]);
        grid on
        drawnow
        pause(delay);
    end

end