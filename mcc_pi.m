function [v_krogu,izven_kroga] = mcc_pi(stevilo_tock)

    % Generiranje naključnih koordinat znotraj kvadrata na intervalu od -1
    % do +1 v dvostolpičnem zapisu
    koordinate = -1 + 2*rand(stevilo_tock, 2);

    % Preverjanje če točke ležijo znotraj kroga
    razdalje = sqrt(koordinate(:,1).^2 + koordinate(:,2).^2);
    
    % Ločevanje točk znotraj in zunaj kroga
    tocke_v_krogu = koordinate(razdalje <= 1, :);
    tocke_izven_kroga = koordinate(razdalje > 1, :);

    % Zapis v sezname
    v_krogu = tocke_v_krogu;
    izven_kroga = tocke_izven_kroga;

end
