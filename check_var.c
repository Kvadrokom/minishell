#include "parser.h"

char	*ft_subline(char *line)
{
	int 	i;
	int 	len;
	char	*subline;

	i = 0;
	len = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\'')
	{
		len++;
		i++;
	}
	subline = malloc(len + 1);
	ft_strncpy(subline, line, len);
	return (subline);
}

char	*ft_new_line(char *str_new, char *line)
{
	char	*newline;
	char	*ptr;
	int		len;

	ptr = NULL;
	newline = NULL;
	ptr = ft_strchr(line, '$');
	if (ptr)
	{
		len = ft_strlen(line) - ft_strlen(ptr);
		newline = (char *)malloc(len + ft_strlen(str_new) + 1);
		ft_strncpy(newline, line, len);
		ft_strncpy(newline + len, str_new, ft_strlen(str_new));
		free(line);
	}
	return (newline);
}

char	*check_var(char *line)
{
	int 	i;
	char	*str_new;
	char	*tmp;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			str_new = ft_subline(&line[i]);
			tmp = str_new;
			str_new = getenv(str_new + 1);
			if (str_new)
			{
				line = ft_new_line(str_new, line);
				free(tmp);
				return (line);
			}
			free(tmp);
		}
		i++;
	}
	return (line);
}

// int main()
// {
// 	char *new;
// 	char *str = strdup("wetetr$PWD");
// 	new = check_var(str);
// 	// new = getenv("PWD");
// 	printf("%s\n", new);
// 	sleep(1000);
// 	return 0;
// }