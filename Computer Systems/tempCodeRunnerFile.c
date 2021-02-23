case 'r':
                scanf("%d", &index);
                remove_element(&list, index);
                print_list(&list);
                break;