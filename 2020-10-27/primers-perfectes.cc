bool es_primer(int n)
{
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int suma_digits(int n)
{
    if (n <= 9) {
        return n;
    }
    return n % 10 + suma_digits(n / 10);
}

// lent:

bool es_primer_perfecte(int n)
{
    if (not es_primer(n)) {
        return false;
    }
    if (n <= 9) {
        return true;
    }
    return es_primer_perfecte(suma_digits(n));
}

// més eficient:

bool es_primer_perfecte(int n)
{
    if (n <= 9) {
        return es_primer(n);
    }
    if (not es_primer_perfecte(suma_digits(n))) {
        return false;
    }
    return es_primer(n);
}

// amb un sol return i operacions lògiques

bool es_primer_perfecte(int n)
{
    return (n <= 9 and es_primer(n))
        or (es_primer_perfecte(suma_digits(n)) and es_primer(n));
}
