function [pi_priblizek, odstopanje] = calc_pi(stevilo_tock)
    
    % Ustvarjanje dveh seznamov
    [v_krogu, izven_kroga] = mcc_pi(stevilo_tock);

    % Izračun približka za pi in odstopanja
    [pi_priblizek, odstopanje] = area_pi(v_krogu, izven_kroga);

    % Podatki za uporabo v anonimni funkcijicl
    theta = linspace(0, 2*pi, 100);
    radius=1;

    % Anonimna funkcija
    kroznica = @(theta, radius) [radius * cos(theta); radius * sin(theta)];
    kroznica_tocke = kroznica(theta, radius);

    % Vizualizacija
    figure;
    scatter(v_krogu(:,1), v_krogu(:,2), 'b', 'filled'); % Točke znotraj kroga so modre
    hold on;
    scatter(izven_kroga(:,1), izven_kroga(:,2), 'r', 'filled'); % Točke izven kroga so rdeče
    plot(kroznica_tocke(1, :), kroznica_tocke(2, :), 'green', 'LineWidth', 5);
    axis equal;
    title('Računanje približka števila pi');
    legend({'Točke v krogu', 'Točke zunaj kroga', 'Krožnica'});
    xlabel('X os');
    ylabel('Y os');
    
    % Prikaz rezultatov
    fprintf('Približek za pi: %.6f\n', pi_priblizek);
    fprintf('Odstopanje od števila pi: %.6f\n', odstopanje);
end

function [pi_priblizek, odstopanje] = area_pi(v_krogu, izven_kroga)
    % Števila točk v seznamih
    st_tock_v_krogu = size(v_krogu, 1);
    st_tock_izven_kroga = size(izven_kroga, 1);
    
    skupno_st_tock = st_tock_v_krogu + st_tock_izven_kroga;
    
    % Približek za pi
    pi_priblizek = 4 * st_tock_v_krogu / skupno_st_tock;
    
    % Odstopanje od števila pi
    odstopanje = abs(pi - pi_priblizek);
end

