import re
""" match = re.match(r'[1-9]\d{5}', '100081 BIT')
if match:
    print(match.group()) """
ls = re.findall(r'[1-9]\d{5}', 'BIT100081 TSU 100084')
if ls:
    print(ls)