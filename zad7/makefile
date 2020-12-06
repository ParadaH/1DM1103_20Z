all:
	gcc baza.c main.c -o mydb -Wall --pedantic

test: all	
	./mydb baza.csv listofstudents

test_dodaj_studenta: all
	./mydb baza.csv addstudent Jan Kowalski 123456 www@gmail.com

test_dodaj_przedmiot: all
	./mydb baza.csv addcourse 1DM1103_20Z "Podstawy programowania" 2020Z

test_dodaj_studenta_do_przedmiotu: all
	./mydb baza.csv addstudenttocourse 1DM1103_20Z 123456

test_ile_studentow: all
	./mydb baza.csv countstudents

test-zwalnianie_pamieci: all
	valgrind ./mydb baza.csv countstudents
	