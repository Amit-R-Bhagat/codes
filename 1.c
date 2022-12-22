male(jim)
male(bob)
male(tom)
male(peter)
parent(pam,bob)
parent(tom,bob)
parent(tom,liz)
parent(bob,ann)
parent(bob,pat)
parent(pat,jim)
parent(bob,peter)
parent(peter,jim)
mother(X,Y): - parent(X,Y),female(X).
father(X,Y):- parent(X,Y),male(X).
haschild(X):- parent(X,_).
sister(X,Y):- parent(Z,X),parent(Z,Y),female(X),X\==Y.
brother(X,Y):- parent(Z,X),parent(Z,Y),male(X),X\==Y.

?- mother(X,Y).
X = pam.
Y = bob.

?- mother(X,Y).
X = pam.
Y = bob.

?-
|	sister(X,bob).
X = liz.

?- brother(X,pam).
false.

?- brother(X,peter).
false

?- father(X,pat).
X = bob.

?- mother(X,jim).
X = pat
