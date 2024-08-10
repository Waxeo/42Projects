# Minishell
Quelques conseils pour Minishell : 


-Organisez vous, faites un plan d'action et partez du plus important, cela vous amenera logiquement et simplement vers les differents details du projets.


-Le plus important sera la partie execution de commande et redirections, vous pouvez commencer a faire des builtins pour vous detendre au besoin mais le parsing devra etre fait pour l'éxecution et elle doit etre parfaitement fonctionnel, si vous avez ça le reste sera une formalité.


-Les deux choix les plus probants pour le parsing sont le lexer si vous avez des facilités avec les listes chainées, ou, les splits tableaux.


o Le lexer consiste a tokeniser chacun des agruments avec pour chaque node de la liste, un mot et un int qui le définira comme fichier, commande, pipe...
un exemple avec <in cat | cat >out, le premier maillon sera < avec pour int 0 qui sera associé a un redirection d'entrée, in est après un int 0 donc est un nom de fichier disons int = 1..etc vous n'aurez qu'à jouer avec le delete des nodes qui contiennent les redirections une fois que vous aurez redirigé vos commandes, et a mettre en tableau le reste et le donner a exceve.


o Autre cas de figure, plus simple je trouve, le split. Si on reprend notre commande <in cat | cat >out nous allons commencer par rajouter un espace a tous nos caracteres spéciaux pour avoir < in cat | cat > out, ça nous simplifiera la vie. Ensuite on split cette commande aux pipes, soit tab[0] = <in cat et tab[1] = cat >out (vous devrez evidemment parser certains cas au fur et a mesure avec les quotes et autres). Chaque maillon de notre tableau est donc une commande, arrivé dans notre processus enfant, on split aux espaces pour avoir toute notre commande dans un tableau, et il reste plus qu'a trouver si un maillon du tableau est un chevron, si oui on tente d'ouvrir tab[i + 1] pour rediriger, et le reste on y touche pas. Il restera plus qu'a retirer de notre tableau nos redirections et enviyer notre reste de tableau a exceve. Tout cela en prenant en compte toujours le parsing des quotes, expands etc...


Avec une execution de commande efficace et fonctionnel, le reste sera relativement simple.
!N'oubliez pas que vous n'avez pas le droit d'utiliser les fichiers de commandes existants parmis les builtins demandés ; echo est passable a exceve mais forcément, vous n'y avez pas le droit, donc vous devrez jongler entre execve et vos builtins pour certaines commandes.


Vous decouvrirez au fur et a mesure les cas trickys et problématique a gérer :')
Bon courage ! 
