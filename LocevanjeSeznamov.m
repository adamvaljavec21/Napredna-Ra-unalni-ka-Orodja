(* ::Package:: *)

LocevanjeSeznamov[seznam_]:= Module[
{notri,zunaj},
notri=Select[seznam,Norm[#]<=1&];
zunaj=Select[seznam,Norm[#]>1&];
{notri,zunaj}]

