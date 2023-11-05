void Recursive(int depth)
{
    if (depth > 0)
    {
        Recursive(--depth);
    }
}

void CallRecursive()
{
    Recursive(0x7fffffff);
}

int main()
{
    CallRecursive();
}
