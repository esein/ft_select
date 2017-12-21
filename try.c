			if (elem->next != NULL)
				elem->next->prev = elem->prev;
			if (elem->prev != NULL)
				elem->prev->next = elem->next;
			else
				first = elem->next;
			if (first == NULL)
				return (NULL);
			if (elem->cursor_on == 1)
			{
				if (elem->next != NULL)
					elem->next->cursor_on = 1;
				else
					first->cursor_on = 1;
			}
			elem = ft_free(elem);
			elem = first;
