Also classified by,

- Those that need a host program (parasitic code such as viruses)
- Those that are independent, self-contained programs (worms, trojans, and bots)
- Malware that does not replicate (trojans and spam e-mail)
- Malware that does replicate (viruses and worms)

User input,

- Attackers inject SQL commands by providing suitable crafted user inputServer variables
- Attackers can forge the values that are placed in HTTP and network headers and exploit this vulnerability by placing data directly into the headers

Second-order injection,

- A malicious user could rely on data already present in the system or database to trigger an SQL injection attack, so when the attack occurs, the input that modifies the query to cause an attack does not come from the user, but from within the system itself

Cookies,
- An attacker could alter cookies such that when the application server builds an SQL query based on the cookie’s content, the structure and function of the query is modified

Physical user input,
-Applying user input that constructs an attack outside the realm of web requests
