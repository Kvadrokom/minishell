#include "parser.h"

void	parce_dbl_quote(char *line)
{
	check_var(line);
}

void	parce_one_quote(char *line)
{
	char	*tmp;

	tmp = malloc(ft_strlen(line) - 2);
	if (!tmp)
	{
		perror("Error one quote malloc");
		exit(EXIT_FAILURE);
	}
	ft_strncpy(tmp, (line + 1), ft_strlen(line) - 1);
	free(line);
	line = tmp;
}

void	quote(char *line)
{
	if (*line == '\'')
		parce_one_quote(line);
	else if (*line == '\"')
		line = check_var(line);
}