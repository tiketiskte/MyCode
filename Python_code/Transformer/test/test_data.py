from Data import LoadEnglishGermanDataset,my_tokenizer


if __name__ == '__main__':
    train_filepath = ['Python_code/Transformer/data/train.de', 'Python_code/Transformer/data/train.en']
    data_loader = LoadEnglishGermanDataset(train_filepath, tokenizer=my_tokenizer, batch_size=2)

    train_iter, val_iter, test_iter = data_loader.load_train_val_test_data(train_filepath, train_filepath, train_filepath)

    print(data_loader.PAD_IDX)

    for src, tgt in train_iter:
        tgt_input = tgt[:-1, :]
        tgt_output = tgt[1:, :]
        src_mask, tgt_mask, src_padding_mask, tgt_padding_mask = data_loader.create_mask(src, tgt_input)
        print("src shape:", src.shape) # [de_coder_len, batch_size]
        print("src_padding_mask shape(batch_size, src_len):", src_padding_mask.shape)
        print("tgt input shape:", tgt_input.shape)
        print("tgt_padding_mask shape(batch_size, tgt_len):", tgt_padding_mask.shape)
        print("tgt output shape:", tgt_output.shape)
        print("tgt mask shape(tgt_len, tgt_len):", tgt_mask.shape)
        break