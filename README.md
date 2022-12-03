# E-commerce-Customer-Database

Database to manage set of customer

Database consist of
<ul>
  <li>
    Name 
    <ul> 
      <li> Any combination of letters, digits and spaces</li>
    </ul>
  </li>
  <li>
    Email address
    <ul> 
      <li> At least 8 characters long and no longer than 12 characters</li>
      <li> Must contain at least one upper case letter</li>
      <li> Must contain at least one lower case letter</li>
      <li> Must contain at least two digits</li>
      <li> Must contain at least one of the following special characters: ? @ % $ #</li>
      <li> Must not contain any other special characters not in the list above.</li>
    </ul>
  </li>
  <li>
    Password
    <ul> 
      <li> No embedded spaces or special characters anywhere in the email address, except period (.), at-sign (@), underscore (_) and/or dash (-)</li>
      <li> Must begin with an alphanumeric (letter or digit) character</li>
      <li> Exactly one occurrence of the at-sign (@)</li>
      <li> At least one alphabetic or numeric character before the at-sign</li>
      <li> Address must end in one of: .com, .net, .ac.th, or .co.th (top-level domains or TLD)</li>
      <li> At least one alphanumeric character between the at-sign and the TLD.</li>
      <li> No underscores after the at-sign.</li>
      <li> At least one alphanumeric character between any periods that occur after the at-sign.</li>
    </ul>
  </li>
  <li>
    Last order date
    <ul> 
      <li> ‘MMM’ is first 3 chars of month, capital letters. As above, you must make sure that the date is both formatted correctly and a legal date. Years cannot be more than 100 years in the past or the future.</li>
    </ul>
  </li>
  <li>
    Country of Residence 
    <ul> 
      <li> Two letter code must match one of the list</li>
    </ul>
  </li>
  <li>
    Address
    <ul> 
      <li> Any combination of letters, digits, spaces and periods</li>
    </ul>
  </li>
</ul><br>
Can Search using 
<ul>
  <li>
    Email Address - Partial Match Possible
  </li>
  <li>
    Name - Partial Match Possible
  </li>
</ul>
