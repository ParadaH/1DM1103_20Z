all:
	gcc baza.c main.c -o mydb -Wall --pedantic

test: all	
	./mydb baza1.csv listofstudents

test_dodaj_studenta: all
	./mydb baza1.csv addstudent Jan Kowalski 123456 www@gmail.com

test_dodaj_przedmiot: all
	./mydb baza1.csv addcourse 1DM1103_20Z "Podstawy programowania" 2020Z

test_dodaj_studenta_do_przedmiotu: all
	./mydb baza1.csv addstudenttocourse 1DM1103_20Z 123456

test_ile_studentow: all
	./mydb baza1.csv countstudents

test-zwalnianie_pamieci: all
	valgrind ./mydb baza1.csv countstudents
	